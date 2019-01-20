def f():
	def g():
		print 99
	g()

def g():
	print 7

f()
g()

