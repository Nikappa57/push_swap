import sys

def main():
	if len(sys.argv) != 2:
		return
	file_path = sys.argv[1]

	with open(file_path) as f:
		moves = [s.strip() for s in f.read().splitlines() if s.strip()]
	print("-"* 20, "CHECK 1", "-"* 20)
	moves_n = {'ra': {'n': 0, 'pos': []}, 
	    		'rb': {'n': 0, 'pos': []}, 
				'rra': {'n': 0, 'pos': []}, 
				'rrb': {'n': 0, 'pos': []}}
	for move_i, move in enumerate(moves):
		if move in moves_n.keys():
			moves_n[move]['n'] += 1
			moves_n[move]['pos'].append(move_i + 1)
		if move in ('pa', 'pb') or move_i == len(moves) - 1:
			i = 0
			while (i < len(keys:=list(moves_n.keys())) - 1):
				if (moves_n[keys[i]]['n'] and moves_n[keys[i + 1]]['n']):
					print(f"{moves_n[keys[i]]['pos']} | {moves_n[keys[i + 1]]['pos']}:")
					print(f"{keys[i]}: {moves_n[keys[i]]['n']} | {keys[i + 1]}: {moves_n[keys[i + 1]]['n']}")
					print("-" * 60)
				i += 2
			for key in keys:
				moves_n[key] = {'n': 0, 'pos': []}
	moves_n = {'ra': {'n': 0, 'pos': []}, 
	    		'rb': {'n': 0, 'pos': []}, 
				'rra': {'n': 0, 'pos': []}, 
				'rrb': {'n': 0, 'pos': []}}
	print("-"* 20, "CHECK 2", "-"* 20)
	for move_i, move in enumerate(moves):
		if move in moves_n.keys():
			moves_n[move]['n'] += 1
			moves_n[move]['pos'].append(move_i + 1)
		if move in ('pa', 'pb', 'sa', 'sb') or move_i == len(moves) - 1:
			i = 0
			while (i < len(keys:=list(moves_n.keys())) - 2):
				if (moves_n[keys[i]]['n'] and moves_n[keys[i + 2]]['n']):
					print(f"{moves_n[keys[i]]['pos']} | {moves_n[keys[i + 2]]['pos']}:")
					print(f"{keys[i]}: {moves_n[keys[i]]['n']} | {keys[i + 2]}: {moves_n[keys[i + 2]]['n']}")
					print("-" * 60)
				i += 1
			for key in keys:
				moves_n[key] = {'n': 0, 'pos': []}

if __name__ == "__main__":
	main()