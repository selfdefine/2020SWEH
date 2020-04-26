import React from 'react'
import { Checkbox, Row, Col } from 'antd';

export default class SelectOperator extends React.Component {
  render () {
    const { onChange } = this.props
    return (
      <Checkbox.Group defaultValue={['+']} style={{ width: '100%' }} onChange={onChange}>
        <Row>
          <Col span={12}>选择操作符(默认为+)</Col>
        </Row>
        <Row>
          <Col span={4}>
            <Checkbox value="+">+</Checkbox>
          </Col>
          <Col span={4}>
            <Checkbox value="-">-</Checkbox>
          </Col>
          <Col span={4}>
            <Checkbox value="×">×</Checkbox>
          </Col>
          <Col span={4}>
            <Checkbox value="÷">÷</Checkbox>
          </Col>
        </Row>
      </Checkbox.Group>
    )
  }
}