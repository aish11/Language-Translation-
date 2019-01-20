def f():
	x=100
	print x
	if(x>90):
		print 1
		if(x>100):
			print 2
			return 80
		else:
			print 3
			return 70
	else:
		print 4
	print 5

print f()
