class Solution:
    def isValid(self, s: str) -> bool:
        
        open_paran = ['(', '{', '[']
        
        paran_list = []
       
        valid = True
        for paran in s:
            if paran in open_paran:
                paran_list.append(paran)
            
            if not paran_list:
                valid = False
                break
            elif paran ==')' and paran_list.pop() !='(' or \
                paran ==']' and paran_list.pop() !='[' or \
                paran =='}' and paran_list.pop() !='{':
                    valid = False
                    break
        else:
            if paran_list:
                valid = False
        
        return valid
