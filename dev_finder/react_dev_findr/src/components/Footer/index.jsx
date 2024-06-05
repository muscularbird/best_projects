import styled from "styled-components";
import { Link } from "react-router-dom";
import colors from "../../utils/colors";
import { useContext } from "react";
import { ThemeContext } from "../../utils/context";

const FooterStyled = styled.div`
  display: flex;
  flex-direction: column;
  align-items: center;
  justify-content: center;
  padding-top: 60px;
`;

const AllLink = styled.div`
    display: flex;
    flex-direction: row;
    align-items: center;
    margin-bottom: 1em;
`;

const NightModeButton = styled.div`
  position: relative;
  border: none;
  cursor: pointer;
  border-radius: 3px;
  width: 70px;
  height: 32px;
  margin: 50px;
  background-color: ${colors.secondary};
`;

const Button = styled.div`
  display: flex;
  justify-content: center;
  align-items: center;
  box-sizing: border-box;
  width: 38px;
  cursor: pointer;
  background-color: ${colors.primary};
  box-shadow: 0 2px 4px rgb(0, 0, 0, 0.25);
  border-radius: 3px;
  padding: 8px 12px;
  position: absolute;
  transition: all 0.2s ease;
  line-height: 16px;
  left: ${({ isDarkMode }) => (isDarkMode ? "0px" : "32px")};
`;

const StyledLink = styled(Link)`
  margin: 10px;
  color: ${({ isDarkMode }) => (isDarkMode ? `${colors.secondary}` : `${colors.primary}`)};
  text-decoration: none;
`;

function Footer() {
  const { toggleTheme, theme } = useContext(ThemeContext);
  const isDarkMode = theme === "dark";

  return (
    <FooterStyled>
      <NightModeButton onClick={toggleTheme}>
        <Button isDarkMode={isDarkMode}>{isDarkMode ? "🌙" : "☀️"}</Button>
      </NightModeButton>
      <AllLink>
        <StyledLink to="/freelance" isDarkMode={isDarkMode}>About us</StyledLink>
        <StyledLink to="/contact" isDarkMode={isDarkMode}>Contact</StyledLink>
      </AllLink>
    </FooterStyled>
  );
}

export default Footer;
