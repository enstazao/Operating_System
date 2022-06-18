from multiprocessing import Process

def f(name):
    print(name)

if __name__ == '__main__':
    p = Process(target=f, args=('Process One',))
    q = Process(target=f, args=('Process Two',))
    r = Process(target=f, args=('Process Three',))
    p.start()
    q.start()
    r.start()
    p.join()
    q.join()
    r.join()
