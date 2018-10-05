const fs = require('fs')
const request = require('request')
const denodeify = require('denodeify')
const cheerio = require('cheerio')
const iconv = require('iconv-lite')

const request_get = denodeify(request.get)


;(async function() {
  let query = '?q=' + encodeURIComponent('abc')
  let url = 'http://google.com/' + query
  let res = await request_get(url)
  //res = iconv.encode(iconv.decode(new Buffer(res.body), 'win1251'), 'utf8')
  //res = JSON.parse(res.body)
  console.log(res.toString())
}())
