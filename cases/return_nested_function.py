def f():
	x=89
	print x
	def g():
		x=67
		if(x>=67):
			return 34
		else:
			return 65
		x+=45
		print x
	y=g()
	print y
	y+=1
	return y
	print y

f()
