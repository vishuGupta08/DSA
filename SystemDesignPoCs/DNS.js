const dgram = require('dgram');
const packet = require('dns-packet');

// Domain-IP mapping
const domainIpMap = {
    'example.com': '93.184.216.34',
    'test.com': '192.0.2.1',
    'localtest.me': '127.0.0.1'
};

// Get IP address for a domain
const getIp = (domain) => {
    return domainIpMap[domain] || '0.0.0.0';
};

// Build DNS response
const buildResponse = (msg, rinfo) => {
    const query = packet.decode(msg);
    const domain = query.questions[0].name;
    const ip = getIp(domain);
    
    const response = {
        type: 'response',
        id: query.id,
        flags: packet.RECURSION_DESIRED | packet.RECURSION_AVAILABLE,
        questions: query.questions,
        answers: [{
            type: 'A',
            class: 'IN',
            name: domain,
            ttl: 300,
            data: ip
        }]
    };

    return packet.encode(response);
};

// Start the DNS server
const server = dgram.createSocket('udp4');

server.on('message', (msg, rinfo) => {
    const response = buildResponse(msg, rinfo);
    server.send(response, 0, response.length, rinfo.port, rinfo.address, (err) => {
        if (err) console.error('Error sending response:', err);
    });
});

server.on('listening', () => {
    const address = server.address();
    console.log(`DNS server listening on ${address.address}:${address.port}`);
});

server.bind(53535); // Bind to port 53, the default DNS port

// After running the node DNS.js
// Run this command on terminal - dig @0.0.0.0 -p 53535 example.com
// Response of my DNS 
/**
 * 
; <<>> DiG 9.16.48-Ubuntu <<>> @0.0.0.0 -p 53535 example.com
; (1 server found)
;; global options: +cmd
;; Got answer:
;; ->>HEADER<<- opcode: QUERY, status: NOERROR, id: 56721
;; flags: qr rd ra; QUERY: 1, ANSWER: 1, AUTHORITY: 0, ADDITIONAL: 0

;; QUESTION SECTION:
;example.com.			IN	A

;; ANSWER SECTION:
example.com.		300	IN	A	93.184.216.34

;; Query time: 0 msec
;; SERVER: 127.0.0.1#53535(0.0.0.0)
;; WHEN: Wed Jul 10 22:35:21 IST 2024
;; MSG SIZE  rcvd: 56

 */
