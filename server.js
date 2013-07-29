var http = require('http');

var fastMath = require('./fastMath/build/Release/fastMath');

http.createServer(function (req, res) {

  var someData = Array(1.2,4.5,3.2,4,5);
  
  var calc1 = fastMath.compute("add", someData);
  var calc2 = fastMath.compute("subtract", someData);
  var calc3 = fastMath.compute("multiply", someData);

  var bodyData = "Addition Result: "+calc1+"\nSubtraction Result: "+calc2+"\nMultiplication Result: "+calc3+"\n"; 

  res.writeHead(200, {'Content-Type': 'text/plain'});
  res.end(bodyData);

}).listen(1337, '127.0.0.1');

console.log('Server running at http://127.0.0.1:1337/');