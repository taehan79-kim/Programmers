def solution(age):
    age_int1 = int(age/1000)+97;
    age_int2 = int(age%1000/100)+97;
    age_int3 = int(age%100/10)+97;
    age_int4 = int(age%10)+97;
    answer = chr(age_int1) + chr(age_int2) + chr(age_int3) + chr(age_int4); 
    answer = answer.lstrip("a");
    return answer;