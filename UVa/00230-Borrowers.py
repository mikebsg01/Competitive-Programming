from sys import stdin

def readLine():
    return stdin.readline().strip()

def print_list(l: list = []):
    for x in l:
        print(x)
    print()

class Solution():
    def get_book_from_request(self, author_by_book: dict = {}, request: str = '') -> tuple:
        title = request.replace('RETURN ', '').replace('BORROW ', '').replace('\"', '')
        author = author_by_book[title]
        return (title, author)

    def get_instructions(self, books: list = [], requests: list = []) -> list:
        shelved_books = list(books)
        shelved_books.sort(key=lambda x: [x[1], x[0]])
        author_by_book = dict((title, author) for (title, author) in books)
        returned_books = []
        instructions = []

        for request in requests:
            if request.startswith('BORROW'):
                book = self.get_book_from_request(author_by_book, request)
                shelved_books.remove(book)
            elif request.startswith('RETURN'):
                book = self.get_book_from_request(author_by_book, request)
                returned_books.append(book)
            else:
                returned_books.sort(key=lambda x: [x[1], x[0]])

                for returned_book in returned_books:
                    shelved_books.append(returned_book)
                    shelved_books.sort(key=lambda x: [x[1], x[0]])
                    index = shelved_books.index(returned_book)
                    prev_book = None if index == 0 else shelved_books[index - 1]

                    if prev_book is None:
                        instructions.append('Put "{}" first'.format(returned_book[0]))
                    else:
                        instructions.append('Put "{}" after "{}"'.format(returned_book[0], prev_book[0]))
                
                returned_books.clear()
                instructions.append('END')

        return instructions


def main():
    books = []
    requests = []

    while True:
        line = readLine()

        if line == 'END':
            break

        title, author = line.split(' by ')
        title = title.replace('\"', '')
        books.append((title, author))

    while True:
        line = readLine()

        if line == 'END':
            break

        requests.append(line)

    solution = Solution()
    instructions = solution.get_instructions(books, requests)
    
    for instruction in instructions:
        print(instruction)

if __name__ == '__main__':
    main()