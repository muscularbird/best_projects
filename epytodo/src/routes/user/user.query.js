const connection = require('../../config/db.js').promise()
const bcrypt = require('bcryptjs')
const jwt = require('jsonwebtoken');
const saltRounds = 10;

const createUser = async (email, password, name, firstname) => {
  try {
    const [userExist] = await getUserByEmail(email);
    if (userExist.length > 0) {
      throw new Error("User already exists");
    }
    let hashedPassword = await bcrypt.hash(password, saltRounds);
    const query = `INSERT INTO user (email, password, name, firstname)
VALUES (?, ?, ?, ?)`;
    return connection.query(query, [email, hashedPassword, name, firstname]);
  } catch(err) {
    throw err;
  }
};

const getAllUser = async () => {
  try {
    const query = `SELECT * FROM user`
    const result = await connection.query(query)
    return result;
  } catch (err) {
    throw err
  }
}

const deleteUserByID = async(id) => {
  try {
    const query = `DELETE FROM user WHERE id = ?`
    const result = await connection.query(query, id)
    return result
  } catch (err) {
    console.log(err)
    throw err
  }
}

const loginUser = async (email, password) => {
  try {
    const query = `SELECT * FROM user WHERE email = ?`;
    const [rows] = await connection.query(query, [email]);
    if (rows.length === 0) {
      throw new Error('Not found');
    }
    const user = rows[0];
    const isPasswordValid = await bcrypt.compare(password, user.password);
    if (!isPasswordValid) {
      throw new Error('Invalid password');
    }
    const token = jwt.sign({ id: user.id, email: user.email }, process.env.SECRET);
    return { token };
  } catch (err) {
    throw err;
  }
};

const getUserByEmail = async (email) => {
  try {
    const query = 'SELECT * FROM user WHERE email = ?';
    const result = await connection.query(query, email);
    return result;
  } catch (err) {
    throw err;
  }
};


const getUserByID = async (id) => {
  try {
    const query = 'SELECT * FROM user WHERE id = ?';
    const result = await connection.query(query, [id]);
    return result[0];
  } catch (err) {
    throw err;
  }
};

const updateUserByID = async (id, email, pwd, mname, fname) => {
  try {
    let hashedPassword = await bcrypt.hash(pwd, saltRounds);
    const updateQuery = 'UPDATE `user` SET email = ?, password = ?, name = ?, firstname = ? WHERE id = ?';
    await connection.query(updateQuery, [email, hashedPassword, mname, fname, id]);
    const selectQuery = 'SELECT id, email, password, created_at, firstname, name FROM user WHERE id = ?';
    return connection.query(selectQuery, [id]);
  } catch (err) {
    throw err;
  }
};


module.exports = {createUser, getAllUser, deleteUserByID, loginUser, getUserByEmail, getUserByID, updateUserByID}

