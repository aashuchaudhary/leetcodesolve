type AllOne struct {
    myDict map[string]int
}

func Constructor() AllOne {
    return AllOne{myDict: make(map[string]int)}
}

func (this *AllOne) Inc(key string) {
    if _, exists := this.myDict[key]; exists {
        this.myDict[key]++
    } else {
        this.myDict[key] = 1
    }
}

func (this *AllOne) Dec(key string) {
    if _, exists := this.myDict[key]; exists {
        if this.myDict[key] > 1 {
            this.myDict[key]--
        } else {
            delete(this.myDict, key)
        }
    }
}

func (this *AllOne) GetMaxKey() string {
    if len(this.myDict) == 0 {
        return ""
    }
    maxKey := ""
    maxVal := 0
    for key, val := range this.myDict {
        if val > maxVal {
            maxVal = val
            maxKey = key
        }
    }
    return maxKey
}

func (this *AllOne) GetMinKey() string {
    if len(this.myDict) == 0 {
        return ""
    }
    minKey := ""
    minVal := int(^uint(0) >> 1) // Max int value
    for key, val := range this.myDict {
        if val < minVal {
            minVal = val
            minKey = key
        }
    }
    return minKey
}