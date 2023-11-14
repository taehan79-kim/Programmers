def solution(hp):
    ant1 = int(hp/5)
    ant2 = int((hp%5)/3)
    ant3 = int((hp%5)%3)
    answer = ant1 +ant2 + ant3
    return answer