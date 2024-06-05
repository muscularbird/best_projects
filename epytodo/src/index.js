require('dotenv').config();
const express = require('express');
const todosRoutes = require('./routes/todos/todos.js')
const userRoutes = require('./routes/user/user.js')
const authRoutes = require('./routes/auth/auth.js')
const port = process.env.PORT || 3002;
const app = express();

app.use(express.json());
app.use(authRoutes)
app.use(userRoutes)
app.use(todosRoutes)

app.listen(port, () => {
  console.log(`Example app listening on port ${port}`);
});
