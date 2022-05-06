console.log("Hello World");

const express = require('express')
const app = express()
app.get('/', function(req, res) {
    res.end('Hello World')
})
app.listen(process.argv[2])