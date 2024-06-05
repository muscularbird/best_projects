// Get the client
const mysql = require('mysql2');
require('dotenv').config()

const connection = mysql.createConnection({
  host: process.env.HOST,
  user: process.env.MYSQL_USER,
  database: process.env.MYSQL_DATABASE,
  password: process.env.MYSQL_ROOT_PASSWORD,

});

connection.connect((err) => {
  if (err) {
    console.error('Erreur de connexion:', err);
    return;
  }
  console.log('Connecté à la db');
});

module.exports = connection;
