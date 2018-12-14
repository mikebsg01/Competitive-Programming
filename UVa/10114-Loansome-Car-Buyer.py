from sys import stdin
from decimal import Decimal as dec

def readLine():
	return stdin.readline().strip()

def readDecimals():
	return list(map(dec, readLine().split()))

def dd(**args):
	print(args)

def main():
	depreciation = lambda x, p: x * (dec('1.0') - p)

	while True:
		months, down_payment, amount_loan, depreciation_months = readDecimals()

		if months < 0:
			break

		depreciation_months = int(depreciation_months)
		dep = [{'id': 0, 'percent': 0} for i in range(depreciation_months)]

		for i in range(depreciation_months):
			dep[i]['id'], dep[i]['percent'] = readDecimals()
			dep[i]['id'] = int(dep[i]['id'])

		monthly_payment = amount_loan / months
		months = int(months)
		current_percent = dep[0]['percent']
		car_worth = depreciation(amount_loan + down_payment, current_percent)
		i, j = 0, 1

		while amount_loan >= car_worth:
			i += 1

			if j < depreciation_months and dep[j]['id'] == i:
				current_percent = dep[j]['percent']
				j += 1

			car_worth = depreciation(car_worth, current_percent)
			amount_loan -= monthly_payment

		print('%d month%s' %(i, 's' if i != 1 else ''))

if __name__ == '__main__':
	main()
