import randomNum from './randomNum'

function getOperator (selected) {
  return randomNum(0, selected.length - 1)
}

//判断生成的算数是否有意义
function isLegal (b, c, op1, op2, brackets, position) {
  //除零
  if ((op1 === '÷' && b === 0) || (op2 === '÷' && c === 0))
    return false
  if ((b === c && op2 === '-' && op1 === '÷'))
    return false
  //无意义的括号
  if (brackets) {
    if (position) {
      if (op1 === '×' || op1 === '÷')
        return false
      if ((op2 === '+' || op2 === '-') && (op1 === '+' || op1 === '-'))
        return false
    }
    else {
      if ((op1 === '+' || op1 === '-') && (op2 === '×' || op2 === '÷'))
        return false
    }
  }
  return true
}


export default function generator (settings) {
  const { amount, maxNumer, brackets, decimal, selected } = settings
  // console.log(amount, maxNumer, brackets, decimal, selected)
  let subjects = []
  let a, b, c, op1, op2, position
  for (let i = 0; i !== amount; i++) {
    do {
      a = randomNum(0, maxNumer, +decimal)
      b = randomNum(0, maxNumer, +decimal)
      c = randomNum(0, maxNumer, +decimal)
      op1 = selected[getOperator(selected)]
      op2 = selected[getOperator(selected)]
      position = randomNum(0, 1, 0)
    }
    while (!isLegal(b, c, op1, op2, brackets, position))
    if (!brackets) {
      subjects[i] = a + op1 + b + op2 + c + '='
    }
    else {
      if (position) {
        subjects[i] = '(' + a + op1 + b + ')' + op2 + c + '='
      }
      else {
        subjects[i] = a + op1 + '(' + b + op2 + c + ')='
      }

    }
  }
  return subjects
}

// module.exports = { isLegal, generator, getOperator };