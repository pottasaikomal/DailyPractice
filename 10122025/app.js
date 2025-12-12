const express = require('express');
const { query } = require('./db');

const app = express();
app.use(express.json());

app.get('/users', async (req, res) => {
    try {
        await query(`
      CREATE TABLE IF NOT EXISTS users (
        id SERIAL PRIMARY KEY,
        name TEXT NOT NULL
      );
    `);
    await query("INSERT INTO users(name) VALUES ($1)", ["Komal"]);
        const result = await query('SELECT * FROM users');
        res.json(result.rows);
    } catch (err) {
        console.error(err);
        res.status(500).send('Server Error');
    }
});

const PORT = process.env.PORT || 3000;
app.listen(PORT, () => {
    console.log(`Server is running on port ${PORT}`);
});