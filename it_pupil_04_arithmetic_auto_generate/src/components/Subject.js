import React from 'react';
import { Row, Col } from 'antd';


export default class SlideBar extends React.Component {
  render () {
    const { subjects } = this.props;
    return (
      <Row >
        {subjects.map((data, i) =>
          (
            <Col span={10} key={i}>
              <div style={{ paddingLeft: '10%', lineHeight: '2.5' }}>{data}</div>
            </Col>
          )
        )}
      </Row>
    );
  }
}