const connection = require('../../config/db.js').promise()

const getAllTodo = async () => {
  try {
    const query = `SELECT * FROM todo`;
    const result = await connection.query(query);
    return result
  } catch (err) {
    throw err;
  }
};

const postAllTodo = async (due_time, title, description, user_id, status) => {
  try {
    const query = `INSERT INTO todo (due_time, title, description, user_id, status) VALUES (?, ?, ?, ?, ?)`
    return connection.query(query, [due_time, title, description, user_id, status])
  } catch (err) {
  }
}

const getUserTodo = async(userId) => {
  try {
    const query = `SELECT * FROM todo WHERE (user_id) = ? `
    const result = await connection.query(query, [userId]);
    return result
  } catch (err) {
    throw err
  }
}

const deleteTodo = async(todoID) => {
  try {
    const query = `DELETE FROM todo WHERE id = ?`
    const result = await connection.query(query, todoID)
    return result
  } catch (err) {
    throw err
  }
}

const getTodoByID = async(todoID) => {
  try {
    const query = `SELECT * FROM todo WHERE id = ?`
    return connection.query(query, [todoID])
  } catch (err) {
  } throw err
}

const updateTaskByID = async (id, title, desc, due_time, user_id, status) => {
  try {
    const query = 'UPDATE `todo` SET title = ?, description = ?, due_time = ?, user_id = ?, status = ? WHERE id = ?';
    await connection.execute(query, [title, desc, due_time, user_id, status, id]);
    const [updatedTodo] = await connection.query('SELECT id, title, description, created_at, due_time, user_id, status FROM todo WHERE id = ?', [id]);
    return updatedTodo;
  } catch (err) {
    throw err;
  }
};

module.exports = { postAllTodo, getAllTodo, getUserTodo, deleteTodo, getTodoByID, updateTaskByID}

