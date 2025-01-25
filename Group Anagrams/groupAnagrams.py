class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        # create a dictionary to group anagrams
        anagrams = defaultdict(list) 

        for word in strs:
            # sort the word and use that as the key
            key = ''.join(sorted(word))
            anagrams[key].append(word) #add the word to the dictionary using the key that is the sorted alphabet

        return list(anagrams.values()) # return list of grouped anagrsms from the dictionary  basically all values in dict except keys
