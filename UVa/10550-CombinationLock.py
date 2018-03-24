from sys import stdin

def dist(cm, a, b):
	return (cm + a - b) % cm

def distInDegrees(cm, a, b):
	return (360 / cm) * dist(cm, a, b)

def main():
	CALIBRATION_MARKS = 40
	answers = []

	for line in stdin:
		pos = list(map(int, line.split()))
		
		if all(p == 0 for p in pos):
			break
	
		total = int((3 * 360) + \
			 distInDegrees(CALIBRATION_MARKS, pos[0], pos[1]) + \
			 distInDegrees(CALIBRATION_MARKS, pos[2], pos[1]) + \
			 distInDegrees(CALIBRATION_MARKS, pos[2], pos[3]))	
		
		print(total)

if __name__ == '__main__':
	main()
