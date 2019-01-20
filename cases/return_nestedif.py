def f():
	x=98
	print x
	if(x>90):
		print 1
		if(x>80):
			print 2
			return 80
		else:
			print 3
	else:
		print 4
	print 5

f()
