from sys import stdin

def main():
	langs = {'HELLO': 'ENGLISH', 'HOLA': 'SPANISH', 'HALLO': 'GERMAN', 'BONJOUR': 'FRENCH', 'CIAO': 'ITALIAN', 'ZDRAVSTVUJTE': 'RUSSIAN'}
	i = 1

	while True:
		word = stdin.readline().split()[0]

		if word == '#':
			break

		print('Case %d: %s' %(i, langs[word] if word in langs else 'UNKNOWN'))
		i += 1

if __name__ == '__main__':
	main()
