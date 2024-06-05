const express = require('express');
const app = express()
const router = express.Router();
const createUser = require('../user/user.query.js')
const { postAllTodo, getAllTodo, deleteTodo, getTodoByID, updateTaskByID } = require('./todos.query.js');
const bodyParser = require('body-parser')
const authMiddleware = require('../../middleware/auth');
var urlencodedParser = bodyParser.urlencoded({ extended: false })


router.use(authMiddleware);

router.post("/todos", urlencodedParser,  async (req, res) => {
  try {
    if (!req.body.title || !req.body.description || !req.body.user_id || !req.body.due_time) {
      return res.status(400).json({msg: 'Bad parameter'});
    }
    let title = req.body.title;
    let description = req.body.description; 
    let user_id = req.body.user_id
    let due_time = req.body.due_time
    let status = req.body.status; 
    let todores = await postAllTodo(due_time, title, description, user_id, status);
    const insertId = todores[0].insertId;
    const insertedTodo = {
      id: insertId,
      title: title,
      description: description,
      user_id: user_id,
      due_time: due_time,
      status: status 
    };
    res.status(201).json(insertedTodo);
  } catch (err){
    res.status(500).json({msg: 'Internal server error'})
  }
});

router.get("/todos", async (req, res) => {
  try {
    let [todos] = await getAllTodo();
    res.status(200).json(todos)
  } catch (err) {
    res.status(500).json({msg: 'Internal server error'})
  }
});

router.get("/todos/:id", async(req, res) => {
  let id = req.params.id
  if (!req.params.id) {
  }
  try {
    if (!id) {
      return res.status(400).json({msg: 'Bad parameter'});
    }
    let [todo] = await getTodoByID(id);
    if (todo.length == 0) {
      res.status(404).json({msg: 'Not found'})
    } else {
      res.status(200).json(todo[0])
    }
  } catch (err) {
    res.status(500).json({msg: 'Error server'})
  }
})

router.delete("/todos/:id", async (req, res) => {
  let id = req.params.id
  try {
    let todo = await deleteTodo(id);
    if (todo[0].affectedRows == 0) {
      return res.status(404).json({msg: 'Not found'})
    }
    res.status(200).json({msg: `Successfully deleted record number: ${id}`})
  } catch (err) {
    res.status(500).json({msg: 'Internal server error'})
  }
})

router.put("/todos/:id", urlencodedParser, async (req, res) => {
  try {
    let id = req.params.id
    let title = req.body.title
    let description = req.body.description
    let due_time = req.body.due_time
    let user_id = req.body.user_id
    let status = req.body.status
    if (!title || !description || !due_time || !user_id) {
      return res.status(400).json({msg: 'Bad parameter'});
    }
    await updateTaskByID(id, title, description, due_time, user_id, status)
    let [todo] = await getTodoByID(id)
    if (todo.length == 0) {
      return res.status(404).json({ msg: 'Not found' });
    }
    res.status(200).json(todo[0])
  }
  catch(err) {
    res.status(500).json({msg: 'Internal server error'})
  }
})

module.exports = router;
