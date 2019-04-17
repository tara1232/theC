let data =[
	['f', 'w', 'w', 'g', 'w', 's', 'w', 'w', 'f', 's', 'w', 'w', 'f', 's', 'f', 'w', 'w', 'w', 'g', 's', 'w', 'f', 'w', 'g', 'g', 'f', 's', 'g', 'w', 'f', 'w', 's'],
	['w', 'g', 'w', 'g', 'w', 's', 'w', 'w', 'w', 'w', 's', 'w', 'w', 's', 's', 'w', 's', 's', 'w', 's', 'w', 'w', 'w', 'f', 'w', 's', 'f', 'w', 'w', 'w', 'w', 'w'],
	['w', 'w', 'w', 'g', 's', 'g', 'w', 'w', 'g', 'f', 'g', 's', 's', 'f', 'w', 'w', 's', 'f', 'w', 'w', 'f', 's', 'w', 'w', 'g', 'f', 'w', 'f', 'w', 'g', 'w', 'w'],
	['w', 'w', 'f', 'w', 'w', 's', 'f', 'g', 'w', 'f', 'g', 'w', 'g', 'f', 'w', 'f', 'f', 'w', 'w', 's', 'f', 'w', 'g', 's', 'f', 'w', 's', 'f', 'w', 'g', 'g', 'w'],
	['w', 'w', 'w', 's', 'w', 'w', 's', 'w', 'w', 'w', 'w', 'w', 'g', 'w', 'f', 'g', 'g', 'g', 'g', 'g', 'w', 'w', 'w', 'w', 'w', 'f', 'w', 'f', 's', 's', 'f', 'g'],
	['w', 'f', 'f', 'w', 'w', 's', 'w', 'f', 'g', 'w', 'f', 'g', 'g', 'f', 'w', 'w', 'w', 'g', 'w', 'w', 's', 'w', 'g', 'g', 'g', 'w', 'w', 'w', 'g', 'f', 'w', 'w'],
	['w', 's', 's', 'g', 'g', 'w', 's', 'w', 'w', 's', 'w', 'g', 's', 's', 'g', 'f', 'w', 'w', 'w', 's', 's', 'w', 's', 'w', 'w', 'g', 'g', 'g', 'w', 'w', 'w', 'w'],
	['w', 'f', 'w', 'g', 'f', 'w', 'g', 's', 'g', 'w', 'w', 'w', 'f', 'f', 'f', 'f', 'w', 'w', 's', 'f', 'w', 'w', 'w', 'w', 'w', 'g', 'w', 's', 'w', 'w', 'w', 'w'],
	['w', 'w', 'g', 'w', 'w', 'f', 's', 'g', 's', 's', 'g', 'w', 'w', 's', 'g', 'w', 'w', 'w', 'w', 'w', 's', 'w', 's', 'g', 'w', 'w', 'g', 's', 'w', 'w', 's', 's'],
	['w', 'w', 'f', 'w', 'g', 'w', 'w', 'f', 'g', 's', 'g', 'g', 'w', 'w', 'f', 'f', 'w', 'w', 'g', 'f', 'w', 'w', 'g', 'g', 's', 'w', 'w', 'w', 'g', 'f', 's', 'w'],
	['s', 'g', 'w', 'w', 'w', 'f', 'w', 'w', 'g', 'w', 'g', 'w', 'g', 'w', 'w', 'w', 's', 'w', 'f', 'w', 'w', 's', 'w', 'w', 'f', 'w', 's', 'w', 'w', 's', 'w', 's'],
	['f', 'w', 'w', 'w', 's', 'w', 'w', 'g', 'w', 'f', 'w', 'w', 'w', 'g', 'w', 'w', 's', 's', 'w', 'w', 'g', 'w', 'f', 'w', 'f', 'g', 'w', 'w', 's', 'w', 'f', 's'],
	['w', 'g', 's', 's', 'g', 'w', 'w', 'w', 'g', 'w', 'g', 'w', 'w', 'w', 'w', 'w', 'w', 's', 'w', 'w', 'w', 'w', 'w', 's', 's', 'w', 's', 'w', 'w', 'w', 'g', 'w'],
	['g', 'w', 'w', 'w', 'f', 'w', 'f', 's', 'f', 'g', 'w', 's', 'w', 'w', 'f', 'g', 'w', 'g', 'f', 'w', 's', 'w', 'w', 'w', 'w', 'g', 's', 'w', 'w', 'w', 's', 'w'],
	['w', 'w', 's', 'w', 'w', 'w', 'w', 'w', 'f', 'g', 'w', 's', 'g', 'w', 'g', 'f', 'w', 'g', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'g', 'w', 's', 'w', 'w', 'g', 'w'],
	['w', 'w', 'w', 'w', 'g', 'w', 's', 'w', 'w', 'g', 'w', 'w', 'w', 'w', 'g', 'w', 'w', 'w', 'g', 'w', 's', 'w', 'w', 's', 'w', 'f', 's', 's', 'w', 'g', 's', 'f'],
	['w', 'w', 'w', 'g', 'w', 's', 'f', 'w', 'w', 'w', 'g', 'g', 'w', 'w', 'g', 's', 'w', 'w', 'w', 'f', 'w', 'f', 'w', 'w', 's', 'g', 'w', 'w', 's', 'w', 'w', 'w'],
	['w', 'f', 'w', 'w', 'w', 'w', 'w', 'f', 'w', 'w', 's', 'f', 'f', 'g', 'g', 'w', 'w', 'w', 'g', 'f', 's', 'w', 'w', 'w', 'w', 's', 'f', 'f', 's', 'w', 'w', 'w'],
	['g', 'w', 'w', 'w', 'w', 'w', 'w', 's', 'f', 'w', 'g', 'w', 'w', 'w', 's', 'w', 'w', 'w', 'g', 'w', 'w', 'w', 's', 's', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w'],
	['s', 'w', 's', 's', 's', 'w', 'w', 'w', 's', 'w', 'w', 'w', 'f', 'w', 'g', 'f', 'w', 'w', 'w', 'w', 'f', 'w', 'w', 'w', 'g', 'w', 'f', 'w', 'w', 'f', 'w', 'w'],
	['f', 'g', 'w', 'w', 's', 's', 's', 'f', 'w', 's', 'w', 'w', 'g', 'w', 'w', 'w', 'w', 'w', 'w', 'f', 'w', 'f', 's', 'f', 'w', 's', 'w', 'f', 'w', 'f', 'w', 'g'],
	['g', 'g', 'f', 'w', 'w', 'w', 'w', 'f', 's', 'w', 'w', 'w', 's', 's', 'w', 'w', 'f', 'f', 'w', 'w', 'g', 'w', 'w', 'w', 's', 'w', 'w', 'w', 'f', 'f', 'f', 'w'],
	['f', 'f', 'w', 'w', 'f', 'f', 'f', 's', 's', 'w', 'f', 'f', 'w', 'g', 'w', 'w', 'g', 'w', 'g', 'w', 's', 'w', 'w', 's', 'w', 'w', 'g', 'f', 'w', 'f', 'w', 'f'],
	['w', 'g', 'w', 'w', 'w', 'f', 'w', 'w', 'w', 'w', 'g', 'w', 'g', 's', 'g', 's', 'w', 'w', 's', 'g', 'w', 'g', 'f', 'w', 'g', 'w', 'w', 'g', 'w', 'w', 's', 'w'],
	['w', 'w', 'g', 'f', 'f', 'w', 's', 'w', 'w', 'w', 'w', 'w', 'f', 'f', 's', 'g', 'w', 'w', 'w', 'g', 'w', 'g', 'f', 'w', 'f', 'w', 'g', 'w', 's', 'f', 'f', 'w'],
	['w', 'w', 'g', 'w', 'w', 'g', 'w', 'f', 's', 's', 's', 's', 'w', 'w', 'g', 'f', 'w', 'f', 'g', 'w', 'f', 'w', 's', 'g', 'w', 'w', 'f', 'g', 'w', 's', 'w', 'w'],
	['w', 'w', 's', 'w', 's', 'w', 's', 's', 'w', 'f', 'f', 'g', 'f', 'w', 'w', 'w', 'g', 'w', 'w', 'g', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'g'],
	['w', 'w', 'w', 'w', 'g', 's', 'g', 'w', 'w', 's', 'f', 'f', 'w', 's', 's', 'w', 'f', 'w', 's', 'w', 'w', 'w', 's', 'g', 'w', 'f', 'w', 's', 'w', 'w', 's', 'w'],
	['g', 'w', 'g', 'w', 'g', 'w', 'w', 'w', 'w', 's', 'w', 'w', 'g', 'w', 'w', 'g', 'w', 's', 'g', 'w', 'w', 'w', 'w', 'w', 'w', 'g', 'w', 'w', 'w', 'g', 'f', 'w'],
	['w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 's', 'w', 'f', 'w', 'w', 'f', 'f', 'w', 'w', 'w', 'w', 'w', 's', 'w', 'w', 'g', 'w', 'w', 's', 'w', 'w', 'w'],
	['f', 'w', 's', 'g', 'f', 'f', 'f', 's', 'g', 'w', 'g', 'w', 'w', 'w', 'w', 'g', 'w', 'w', 's', 's', 's', 'w', 'f', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'g'],
	['w', 'w', 'g', 'w', 's', 'w', 'w', 's', 'w', 'g', 's', 'w', 'g', 'g', 'w', 'w', 'w', 'w', 'w', 'g', 'w', 'w', 'f', 's', 'g', 'w', 's', 'w', 'w', 's', 'f', 'w']
];