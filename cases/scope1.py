x=90
def f():
	print x
	def g():
		x=67
		print x
	g()
	print x

f()
print x
