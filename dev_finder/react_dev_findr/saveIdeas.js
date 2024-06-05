import { useParams } from 'react-router-dom'
import styled from 'styled-components';
import { useState } from 'react'

const Homecontainer = styled.div`
  width: 100px;
  display: flex;
  margin: 50px;
  align-items: center;
  flex-direction: column
`

const Balloon = styled.div`
  height: 100px;
  width: 100px;
  border-radius: 50px;
  background-color: red;
  transform: scale(${({ size }) => size});
`

function Survey() {
    const { questionNumber } = useParams()
    const [size, setSize] = useState(1)
    return (
        <div>
            <h1>Questionnaire</h1>
            <h2>Question {questionNumber}</h2>
            <Homecontainer className="Home">
            <h1 onClick={() => setSize(size + 0.1)}>Bonjour</h1>
            <Balloon size={size}/>
    </Homecontainer>
        </div>
    )
}

export default Survey