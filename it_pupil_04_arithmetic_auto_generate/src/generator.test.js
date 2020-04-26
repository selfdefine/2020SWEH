const { isLegal, generator, getOperator } = require('./util/generator');

test('任何数除以零都是不合法的', () => {
  expect(isLegal(0, 1, '÷', '+', false, 1)).toBe(false) //x÷0+1
  expect(isLegal(1, 0, '×', '÷', false, 1)).toBe(false) //x*1÷0
  expect(isLegal(1, 0, '+', '÷', false, 1)).toBe(false) //x+1÷0
  expect(isLegal(1, 1, '÷', '-', true, 0)).toBe(false)  //x÷(1-1)
})

test('任何没有意义的括号都是不合法的', () => {
  expect(isLegal(1, 1, '+', '+', true, 1)).toBe(false)//(x+1)+1
  expect(isLegal(1, 1, '-', '-', true, 1)).toBe(false)//(x-1)-1
  expect(isLegal(1, 1, '×', '×', true, 1)).toBe(false)//(x×1)×1
  expect(isLegal(1, 1, '÷', '÷', true, 1)).toBe(false)//(x÷1)÷1
  expect(isLegal(1, 1, '+', '×', true, 0)).toBe(false)//x+(1×1)
  expect(isLegal(1, 1, '+', '÷', true, 0)).toBe(false)//x+(1÷1)
})

test('有意义的算式是合法的', () => {
  expect(isLegal(1, 1, '+', '÷', true, 1)).toBe(true)//(x+1)÷1
})

test('生成操作符的索引应该小于操作符的数量-1', () => {
  expect(getOperator(['+', '-', '×', '÷'])).toBeGreaterThanOrEqual(0)
  expect(getOperator(['+', '-', '×', '÷'])).toBeLessThan(4)
  expect(getOperator(['+'])).toEqual(0)
})

test('有括号', () => {
  expect(generator({
    amount: 1,
    maxNumer: 20,
    brackets: true,
    decimal: true,
    selected: ['+']
  })[0]).toMatch(/\(*\)/)
})


test('没括号', () => {
  expect(generator({
    amount: 1,
    maxNumer: 20,
    brackets: false,
    decimal: true,
    selected: ['+']
  })[0]).not.toMatch(/\(*\)/)
})


test('有小数', () => {
  expect(generator({
    amount: 1,
    maxNumer: 20,
    brackets: false,
    decimal: true,
    selected: ['+']
  })[0]).toMatch(/\./)
})


test('没小数', () => {
  expect(generator({
    amount: 1,
    maxNumer: 20,
    brackets: false,
    decimal: false,
    selected: ['+']
  })[0]).not.toMatch(/\./)
})


test('生成1个', () => {
  expect(generator({
    amount: 1,
    maxNumer: 20,
    brackets: false,
    decimal: true,
    selected: ['+']
  }).length).toEqual(1)
})


test('生成100个', () => {
  expect(generator({
    amount: 100,
    maxNumer: 20,
    brackets: false,
    decimal: true,
    selected: ['+']
  }).length).toEqual(100)
})