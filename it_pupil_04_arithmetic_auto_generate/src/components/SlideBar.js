import React from 'react';
import { Slider, InputNumber, Row, Col } from 'antd';

export default class SlideBar extends React.Component {

  render () {
    const { inputValue, onChange } = this.props;
    return (
      <Row>
        <Col span={4}>
          <div style={{ textAlign: "center", lineHeight: '2.5' }}>{this.props.text}</div>
        </Col>
        <Col span={12}>
          <Slider
            min={1}
            max={200}
            onChange={onChange}
            value={typeof inputValue === 'number' ? inputValue : 0}
          />
        </Col>
        <Col span={4}>
          <InputNumber
            min={1}
            max={200}
            style={{ margin: '0 16px' }}
            value={inputValue}
            onChange={onChange}
          />
        </Col>
      </Row>
    );
  }
}