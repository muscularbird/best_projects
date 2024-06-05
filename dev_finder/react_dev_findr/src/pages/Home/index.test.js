import {sum} from './'

test ('ma fonction sum', () => {
    const result = sum(7, 3)
    expect(result).toBe(10)
})