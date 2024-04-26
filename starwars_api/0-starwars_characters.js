#!/usr/bin/node

const request = require('request');
const movieId = process.argv[2];

const filmUrl = `https://swapi.dev/api/films/${movieId}/`;

function getCharacterName(url) {
  return new Promise((resolve, reject) => {
    request(url, { json: true, rejectUnauthorized: false }, (error, response, body) => {
      if (error) {
        reject(error);
      } else if (response.statusCode !== 200) {
        reject(new Error(`Failed to get character data: ${response.statusCode}`));
      } else {
        resolve(body.name); // This assumes the response body directly contains the name field
      }
    });
  });
}

request(filmUrl, { json: true, rejectUnauthorized: false }, async (error, response, body) => {
  if (error) {
    return console.error('Failed to get film data:', error);
  }
  if (response.statusCode !== 200) {
    return console.error(`Failed to get film data: ${response.statusCode}`);
  }

  const characterUrls = body.characters;
  const characterPromises = characterUrls.map(url => getCharacterName(url));

  try {
    const characterNames = await Promise.all(characterPromises);
    characterNames.forEach(name => console.log(name));
  } catch (error) {
    console.error(error);
  }
});
