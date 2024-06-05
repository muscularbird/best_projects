import { Link } from "react-router-dom";
import image from "../../Assets/home-illustration.svg";
import styled, { keyframes } from "styled-components";
import colors from "../../utils/colors";

const Cont = styled.div`
  display: flex;
  flex-direction: column;
  align-items: center;
  margin-top: 7em;
  justify-content: center;
  text-align: center;
`;

const StyledPara = styled.p`
  max-width: 300px;
  font-size: 25px;
  margin: 25px;
  color: ${({ theme }) => theme.text};
`;

const StyledHeader = styled.h1`
  font-size: 3em;
  color: ${({ theme }) => theme.primary};
`;

const fadeIn = keyframes`
  from {
    opacity: 0;
  }
  to {
    opacity: 1;
  }
`;

const Button = styled(Link)`
  color: white;
  text-decoration: none;
  height: 50%;
  width: 15%;
  font-size: 1.5em;
  margin: 1em;
  border-radius: 30px;
  background-color: ${colors.primary};
  transition: transform 0.5s, background-color 0.5s, color 0.5s;

  &:hover {
    transform: scale(1.1);
    background-color: ${colors.secondary};
  }
`;

const Image = styled.img`
  max-width: 100%;
  height: auto;
  animation: ${fadeIn} 2.5s ease-in;
  margin-top: 20px;
`;

function Home() {
  return (
    <Cont>
      <StyledHeader>Bienvenue chez Nous</StyledHeader>
      <StyledPara>Repérez vos besoins, on s’occupe du reste, avec les meilleurs talents</StyledPara>
      <Image src={image} alt="Home Illustration" />
      <StyledPara>Qui sommes-nous ?</StyledPara>
      <Button to="/freelance">Nous découvrir</Button>
    </Cont>
  );
}

export default Home;
