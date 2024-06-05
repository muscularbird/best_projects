require('dotenv').config()
const express = require('express');
const router = express.Router();
const bodyParser = require('body-parser')
const { createUser, loginUser } = require('../user/user.query.js')
const jwt = require('jsonwebtoken');

var urlencodedParser = bodyParser.urlencoded({ extended: false })

router.post('/register', urlencodedParser, async (req, res) => {
  try {
    if (!req.body.email || !req.body.password || !req.body.name || !req.body.firstname) {
      return res.status(400).json({ msg: "Bad parameter" });
    }
    let email = req.body.email
    let password = req.body.password
    let name = req.body.name
    let firstname = req.body.firstname
    await createUser(email, password, name, firstname)
    let token = jwt.sign({ email, name }, process.env.SECRET);
    res.status(201).json({ token: token })
  } catch (err) {
    if (err.message === 'User already exists') {
      res.status(409).json({ msg: "Account already exists" });
    } else {
      res.status(500).json({msg: 'Internal server error'})

    }
  }
});

router.post('/login', urlencodedParser, async (req, res) =>  {
  try {
    if (!req.body.email || !req.body.password) {
      return res.status(400).json({ msg: "Bad parameter" });
    }
    let email = req.body.email
    let password = req.body.password
    const user = await loginUser(email, password)
    const token = jwt.sign({ email: user.email, name: user.name }, process.env.SECRET);
    res.status(200).json({ token: token });
  } catch (err) {
    if (err.message === 'Invalid password' || err.message === 'Not found') {
      res.status(401).json({ msg: "Invalid Credentials"})
    } else {
      res.status(500).json({msg: 'Internal server error'})
    }
  }
});

module.exports = router;
