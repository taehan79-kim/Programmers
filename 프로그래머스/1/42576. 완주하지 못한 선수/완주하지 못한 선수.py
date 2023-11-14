from collections import Counter
def solution(participant, completion):
    p = Counter(participant)
    c = Counter(completion)
    answer = str(list((p - c).keys()))[2:-2]
    return answer