var express = require('express')


var app = express()

var ip = process.argv[2] || process.env.NODE_IP || undefined
var port = process.argv[3] || process.env.NODE_PORT || '80'

app.listen(port, ip)
require('dns').lookup(require('os').hostname(), (err, detected_ip, fam) => {
	console.log('Server started at ' + detected_ip + ':' + port)
})


app.use('/', express.static('./static/'))

app.get('/health', function(req, res) { //keep hosting happy
	res.writeHead(200)
	res.end()
})
