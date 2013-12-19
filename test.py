import httplib
from contextlib import closing

if __name__ == '__main__':
    with closing(httplib.HTTPSConnection('nimbledroid.s3.amazonaws.com')) as conn:
        with open('test.c', 'r') as f:
            conn.request('PUT', '/test.c', f, {'x-amz-grant-read': 'emailAddress="junfeng@cs.columbia.edu"'})
            r = conn.getresponse()
            print r.status
