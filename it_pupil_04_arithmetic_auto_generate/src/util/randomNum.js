export default (minNum = 0, maxNumer = 100, decimal = 0) => {

  return parseFloat((Math.random() * (maxNumer - minNum) + minNum).toFixed(decimal))

}