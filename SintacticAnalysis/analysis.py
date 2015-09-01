test = "(sum + 47)/31"

LETTER = 0
DIGIT = 1
UNKNOWN = 99

INT_LIT = 10
IDENT = 11
ASSIGN_OP = 20
ADD_OP = 21
SUB_OP = 22
MULT_OP = 23
DIV_OP = 24
LEFT_PAREN = 25
RIGHT_PAREN = 26


def parse(program):
	idx = 0
	while idx < len(program):
		char = program[idx]
		if char.isdigit():
			while(True):
				idx += 1
				if idx < len(program):
					char += program[idx]
			char = char[:-1]
			yield INT_LIT, char
		idx += 1



def main():
	# fp = open("program.in", "r")
	# program = fp.read()
	for token, lexeme in parse(test):
		print "Next token is: ", token, " Lexeme is: ", lexeme



if __name__ == '__main__':
	main()
