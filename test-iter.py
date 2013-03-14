if __name__ == '__main__':
    a = [1, 2, 3]
    for b in a:
        print b
        a.append(b)
    print len(a)
