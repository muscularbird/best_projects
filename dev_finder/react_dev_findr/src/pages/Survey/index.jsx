import { Link, useParams } from 'react-router-dom'
import { useState, useEffect } from 'react'
import styled from 'styled-components'
import colors from '../../utils/colors'
import { Loader } from '../../utils/style/Atoms'
import { useFetch } from '../../utils/hooks'

const QuestionContent = styled.span`
  margin: 30px;
`

const SurveyContainer = styled.div`
  display: flex;
  flex-direction: column;
  align-items: center;
`

const LinkWrapper = styled.div`
  padding-top: 30px;
  & a {
    color: black;
  }
  & a:first-of-type {
    margin-right: 20px;
  }
`

const QuestionTitle = styled.h2`
  text-decoration: underline;
  text-decoration-color: ${colors.primary};
`

function Survey() {
    const { questionNumber } = useParams()
    const questionNumberInt = parseInt(questionNumber)
    const prevQuestionNumber = questionNumberInt === 1 ? 1 : questionNumberInt - 1
    const nextQuestionNumber = questionNumberInt + 1
    const { isLoading, data, error } = useFetch(`http://localhost:8000/survey`)
    const { surveyData } = data

    if (error) {
      return <span>Il y a eu un problème  de connection à l'API</span>
    }

    return (
        <SurveyContainer>
            <QuestionTitle>Question {questionNumber}</QuestionTitle>
            {isLoading ? (
            <Loader />
            ) :(
            <QuestionContent>{surveyData && surveyData[questionNumber]}</QuestionContent>)}
            <LinkWrapper>
                <Link to={`/survey/${prevQuestionNumber}`}>Précédent</Link>
                {surveyData && surveyData[questionNumberInt + 1] ? (
                    <Link to={`/survey/${nextQuestionNumber}`}>Suivant</Link>
                ) : (
                    <Link to="/results">Résultats</Link>
                )}
            </LinkWrapper>
        </SurveyContainer>
    )
}
 
export default Survey