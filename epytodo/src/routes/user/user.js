const express = require('express');
const router = express.Router();
const jwt = require('jsonwebtoken');
const { getUserTodo } = require('../todos/todos.query');
const { getAllUser, deleteUserByID, getUserByID, getUserByEmail, updateUserByID} = require('./user.query');
const authMiddleware = require('../../middleware/auth'); 
const bodyParser = require('body-parser');
var urlencodedParser = bodyParser.urlencoded({ extended: false })

router.use(authMiddleware);

router.get("/user", urlencodedParser,  async (req, res) => {
  try {
    let users = await getAllUser();
    if (users.length == 0) {
      return res.status(404).json({msg: 'Not found'})
    }
    res.status(200).json(users[0][0]);
  } catch (err) {
    res.status(500).json({msg: 'Internal server error'})
  }
});

router.get("/user/todos",urlencodedParser, async (req, res) => {
  try {
    let userId = 1
    let [todos] = await getUserTodo(userId);
    if (todos.length == 0) {
      res.status(404).json({msg: 'Not found'})
    } else {
      res.status(200).json(todos)
    }
  } catch (err) {
    res.status(500).json({msg : 'Internal server error'});
  }
})

router.get("/users/:id", async (req, res) => {
  try {
    const userId = req.params.id;
    const isEmail = userId.includes('@');
    let user;
    if (isEmail) {
      [user] = await getUserByEmail(userId);
      if (!user) {
        return res.status(404).json({ msg: 'Not found' });
      }
      return res.status(200).json(user[0]);
    } else {
      [user] = await getUserByID(userId);
    }
    if (!user) {
      return res.status(404).json({ msg: 'Not found' });
    }
    res.status(200).json(user);
  } catch (err) {
    res.status(500).json({ msg: 'Internal server error' });
  }
});

router.put("/users/:id",urlencodedParser, async (req, res) => {
  try {
    let userId = req.params.id
    let email = req.body.email 
    let password = req.body.password 
    let name = req.body.name 
    let firstname = req.body.firstname
    if (!email || !password || !name || !firstname) {
      return res.status(400).json({msg: 'Bad parameter'});
    }
    await updateUserByID(userId, email, password, name, firstname)
    let [updatetedUser] = await getUserByID(userId)
    if (!updatetedUser) {
      return res.status(404).json({ msg: 'Not found' });
    }
    res.status(200).json(updatetedUser)
  } catch (err) {
      res.status(500).json({msg : 'Internal server error'})
    }
  });

router.delete("/users/:id", async(req, res) => {
  let id = req.params.id
  try {
    let user = await getUserByID(id);
    if (user.length == 0) {
      return res.status(404).json({ msg: 'Not found' });
    } 
    res.status(200).json({msg : `Successfully deleted record number: ${id}`})
  } catch (err) {
    res.status(500).json({msg: 'Internal server error'})
  }
})

module.exports = router;
