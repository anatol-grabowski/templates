/* global describe, it */
let chai = require('chai')
let expect = chai.expect

let path = require('path')
require('..')

describe('tests', () => {
  it('test1', () => {
    expect(undefined).to.equal(undefined)
  })
})
