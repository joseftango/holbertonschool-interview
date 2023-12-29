#!/usr/bin/node
const request = require('request');
const process = require('process'); 
const arg = process.argv[2]; 

const url = `https://swapi-api.hbtn.io/api/films/${arg}`;

request(url, (error, response, body) => {
  if (error) console.log(error);
  const myobj = JSON.parse(body);
  const chars = myobj.characters;

  for (const u of chars) {
    request(u, (error, response, body) => {
      if (error) console.log(error);
      const obj = JSON.parse(body);

      console.log(obj.name);
    });
	}
});
