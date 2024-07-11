const http = require("http");

const server = http.createServer((req,res)=>{
    res.writeHead(200, { 'Content-Type': 'text/plain' });
    res.end('Response from Backend Server 2\n');
})

server.listen(3002,()=> {
    console.log('Backend Server 1 is listening on port 3002');
})