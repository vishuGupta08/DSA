const http = require("http");

const server = http.createServer((req,res)=>{
    res.writeHead(200, { 'Content-Type': 'text/plain' });
    res.end('Response from Backend Server 1\n');
})

server.listen(3001,()=> {
    console.log('Backend Server 1 is listening on port 3001');
})