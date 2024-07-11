const http = require('http'); // this is built in
const httpProxy = require('http-proxy');  // this is not

// http-proxy module is used to create proxy servers that 
// can forward HTTP requests to other servers. 

// List of backend servers
const servers = [
    { host: 'localhost', port: 3001 },
    { host: 'localhost', port: 3002 },
  ];


  let currentServer = 0;

// Create a proxy server
const proxy = httpProxy.createProxyServer({});

// Create the load balancer server
const server = http.createServer((req, res) => {
    // Select the backend server using round-robin
    const target = servers[currentServer];
    currentServer = (currentServer + 1) % servers.length;
  
    // Forward the request to the selected backend server
    proxy.web(req, res, { target: `http://${target.host}:${target.port}` });
  });

  server.listen(3000, () => {
    console.log('Load Balancer is listening on port 3000');
  });