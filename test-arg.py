import argparse

if __name__ == '__main__':
    parser = argparse.ArgumentParser()
    parser.add_argument('logs', nargs='+')
    args = parser.parse_args()

    print args.logs
