#!/usr/bin/python3
""" Module for counting words in the titles of subreddit posts """

import requests


def count_words(subreddit, word_list):
    """
    Counts the occurrences of specific wordsin the titles
    """
    def recurse(subreddit, word_list, after=None, word_count={}):
        """
        Recursive function to traverse the pages of the subreddit
        """
        word_list = [word.lower() for word in word_list]

        if not word_count:
            for word in word_list:
                word_count[word] = 0

        url = 'https://www.reddit.com/r/{}/hot.json'.format(subreddit)
        headers = {'User-Agent': 'Mozilla/5.0'}
        params = {'after': after}

        response = requests.get(
            url, headers=headers, params=params, allow_redirects=False)

        if response.status_code != 200:
            return None

        data = response.json().get('data')
        children = data.get('children')

        for child in children:
            title = child.get('data').get('title').lower().split()
            for word in word_list:
                word_count[word] += title.count(word)

        after = data.get('after')
        if after:
            return recurse(subreddit, word_list, after, word_count)
        else:
            sorted_count = sorted(
                word_count.items(), key=lambda kv: (-kv[1], kv[0]))
            for word, count in sorted_count:
                if count > 0:
                    print('{}: {}'.format(word, count))

    recurse(subreddit, word_list)
