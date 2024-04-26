#!/usr/bin/node

const request = require('request');
const movieId = process.argv[2];
const url = `https://swapi-api.hbtn.io/api/films/${movieId}/`;

async function fetchCharacterNames(urls) {
    const characterNames = [];
    for (const url of urls) {
        try {
            const characterData = await fetchData(url);
            characterNames.push(characterData.name);
        } catch (error) {
            console.error(`Error fetching character data: ${error}`);
        }
    }
    return characterNames;
}

function fetchData(url) {
    return new Promise((resolve, reject) => {
        request(url, { json: true }, (error, response, body) => {
            if (error) {
                reject(error);
            } else if (response.statusCode !== 200) {
                reject(new Error(`Failed to get data: ${response.statusCode}`));
            } else {
                resolve(body);
            }
        });
    });
}

request(url, { json: true }, async (error, response, body) => {
    if (error || response.statusCode !== 200) {
        console.error(`Error fetching movie data: ${error || response.statusCode}`);
        return;
    }

    try {
        const characterNames = await fetchCharacterNames(body.characters);
        characterNames.forEach(name => console.log(name));
    } catch (error) {
        console.error(`Error fetching character names: ${error}`);
    }
});
