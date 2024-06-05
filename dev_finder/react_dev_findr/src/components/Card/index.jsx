import PropTypes from 'prop-types'
import styled from 'styled-components'
import colors from '../../utils/colors'
import DefaultPicture from '../../Assets/images.jpeg'
import { ThemeContext } from '../../utils/context'
import { useContext } from "react";

const CardLabel = styled.span`
    color: ${colors.secondary};
    fontSize: 22px;
    font-weight: bold;
    margin: auto;
`

const CardImage = styled.img`
    width: 200px;
    height: 200px;
    border-radius: 20px;
    margin: auto;
`

const CardTitle = styled.span`
  color: ${colors.secondary};
  font-size: 22px;
  font-weight: normal;
  align-self: center;
`

const CardWrapper = styled.div`
    display: flex;
    flex-direction: column;
    align-itmes: center;
    padding: 15px;
    border-radius: 20px;
    background-color: ${({ isDarkMode }) => (isDarkMode ? `${colors.backgroundDark}` : `${colors.primary}`)};
    width: 350px;
    transition: 200ms;
    &:hover {
        cursor: pointer;
        box-shadow: 2px 2px 30px #e2e3e9;
    }
`

function Card({ label, title, picture }) {
    const { toggleTheme, theme } = useContext(ThemeContext)
    return (
        <CardWrapper isDarkMode={theme === 'dark'}>
            <CardLabel>{label}</CardLabel>
            <CardImage src={picture} alt="freelance" />
            <CardTitle>{title}</CardTitle>
        </CardWrapper>
    )
}

Card.propTypes = {
    label: PropTypes.string, 
    title: PropTypes.string,
    picture: PropTypes.string,

}


Card.defaultProps = {
    label: '',
    title: '',
    picture: DefaultPicture,
  }

export default Card