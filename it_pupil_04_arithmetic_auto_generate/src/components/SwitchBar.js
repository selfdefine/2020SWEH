import React from 'react'
import { Switch, Row, Col } from 'antd';


export default class SwitchBar extends React.Component {
  // constructor (props) {
  //   super(props)
  // }
  render () {
    const { onChange } = this.props
    return (
      <Row>
        <Col span={4}><div style={{ textAlign: "center" }}>{this.props.text}</div></Col>
        <Col span={4}><Switch defaultChecked onChange={onChange} /></Col>
      </Row>
    )
  }
}