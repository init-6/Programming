import decimal
import itertools
import math

def _compute(area: float):
	k2 = decimal.Decimal(area*area)
	one = decimal.Decimal(1.0)
	alpha = math.asin(k2 - one)/2

	cos = math.cos(alpha) * 0.5
	sin = math.sin(alpha) * 0.5

	return [(cos, sin, 0.0), (-sin, cos, 0.0), (0.0, 0.0, 0.5)]



def _solve(inputstr):
	area = float(inputstr)
	centers = _compute(area)
	template = "{0} {1} {2}\n{3} {4} {5}\n{6} {7} {8}"

	return template.format(*itertools.chain.from_iterable(centers))


def main():
	T = int(input())
	for tc in range(T):
		valstr = input()
		print("Case #" + str(tc+1) + ":")
		print(_solve(valstr))


if __name__ == "__main__":
    main()
